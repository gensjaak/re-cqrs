open Types;
open CommandHandlers;

let handle = (command: command) => {
  switch (command.type_) {
  | CreateOrder(_) => command->CreateOrderHandler.process
  | AddProduct(_) => command->AddProductHandler.process
  | RemoveProduct(_) => command->RemoveProductHandler.process
  | UpdateProductQuantity(_, _) =>
    command->UpdateProductQuantityHandler.process
  };
};
