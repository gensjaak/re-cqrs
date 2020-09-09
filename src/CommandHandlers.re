open Types;

module CreateOrderHandler = {
  let process = (command: command) => {
    command->ignore;

    Js.log2("Order taken into account", command);

    command.payload->Repositories.Order.save;
  };
};

module AddProductHandler = {
  let process = (command: command) => {
    command->ignore;

    command.payload->Repositories.Order.save;
  };
};

module RemoveProductHandler = {
  let process = (command: command) => {
    command->ignore;

    command.payload->Repositories.Order.save;
  };
};

module UpdateProductQuantityHandler = {
  let process = (command: command) => {
    command->ignore;

    command.payload->Repositories.Order.save;
  };
};
