open Types;

let createOrder = (order, next: unit => unit) => {
  let command = {type_: CreateOrder(order), payload: order};

  command->Bus.handle;

  next();
};
