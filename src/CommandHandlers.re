open Types;

module CreateOrderHandler = {
  let process = (order: order, next: callback) => {
    next |> order->Repositories.Order.insert;
  };
};

module AddProductHandler = {
  let process = (product: product, next: callback) => {
    next |> product->Repositories.Product.insert;
  };
};

module RemoveProductHandler = {
  let process = (productId: string, next: callback) => {
    productId->ignore;
    next |> ignore;
  };
};

module UpdateProductQuantityHandler = {
  let process = (productId: string, ~quantity: int, next: callback) => {
    productId->ignore;
    quantity->ignore;
    next |> ignore;
  };
};

module ProductsGetterHandler = {
  let process = (next: callback) => {
    next |> Repositories.Product.selectAll;
  };
};
