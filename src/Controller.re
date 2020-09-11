open Types;

let getProducts = (next: callback) => {
  let command = GetProducts;

  command->Bus.handle(next);
};

let createOrder = (order, next: callback) => {
  let command = CreateOrder(order);

  command->Bus.handle(next);
};
