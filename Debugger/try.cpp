class CartProvider with ChangeNotifier {
    // Other existing code...

    // Method to increment quantity
    Future<void> incrementQuantity(int id, Cart cartItem) async {
        cartItem.quantity++;
        cartItem.productPrice = cartItem.initialPrice * cartItem.quantity;

        await db.updateQuantity(cartItem);
        addTotalPrice(cartItem.initialPrice.toDouble()); // Update total price
        await getData();                                 // Refresh cart data
        notifyListeners();                               // Notify listeners to update UI
    }

    // Method to decrement quantity
    Future<void> decrementQuantity(int id, Cart cartItem) async {
        if (cartItem.quantity > 1) {
            cartItem.quantity--;
            cartItem.productPrice = cartItem.initialPrice * cartItem.quantity;

            await db.updateQuantity(cartItem);
            removeTotalPrice(cartItem.initialPrice.toDouble()); // Update total price
            await getData();                                    // Refresh cart data
            notifyListeners();                                  // Notify listeners to update UI
        } else {
            await removeFromCart(id, cartItem.productPrice.toDouble()); // Remove from cart if quantity is 0
        }
    }
}