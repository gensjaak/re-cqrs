open Types;

module Product = {
  let insert = (product: product, next: callback) => {
    product->ignore;

    Js.log("Save product to database");

    next(true->Js.Json.boolean);
  };

  let selectAll = (next: callback) => {
    Mysql.query(Database.conn, "SELECT * FROM product", result => {
      switch (result) {
      | Ok(results) => Js.log(results.results)
      | Error(error) => Js.log(error##message)
      }
    });

    next(
      [|
        2.->Js.Json.number,
        10.->Js.Json.number,
        3.->Js.Json.number,
        9.->Js.Json.number,
      |]
      ->Js.Json.array,
    );
  };
};

module Order = {
  let insert = (order: order, next: callback) => {
    order->ignore;

    Js.log2("Save order to database", order);

    next(true->Js.Json.boolean);
  };
};
