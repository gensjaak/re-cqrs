open Types;

module Product = {
  let save = (product: product) => {
    product->ignore;

    Js.log("Save product to database");
  };
};

module Order = {
  let save = (order: order) => {
    order->ignore;

    Js.log2("Save order to database", order);
  };
};
