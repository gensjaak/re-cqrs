open Types;
open CommandHandlers;

let handle = (command, next: callback) => {
  next
  |> (
    switch (command) {
    | CreateOrder(order) => order->CreateOrderHandler.process
    | AddProduct(product) => product->AddProductHandler.process
    | RemoveProduct(productId) => productId->RemoveProductHandler.process
    | UpdateProductQuantity(productId, quantity) =>
      productId->UpdateProductQuantityHandler.process(~quantity)
    | GetProducts => ProductsGetterHandler.process
    }
  );
};
