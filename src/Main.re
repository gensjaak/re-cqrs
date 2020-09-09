open Types;

type express;
type response;
type request = Js.Types.obj_val;
type handler = (request, response) => unit;

let getQuery = [%raw "(request) => request.query"];

[@bs.send] external post: (express, string, handler) => unit = "post";
[@bs.send] external get: (express, string, handler) => unit = "get";
[@bs.send] external send: (response, string) => unit = "send";
[@bs.send] external listen: (express, int, unit => unit) => unit = "listen";
[@bs.module] external express: unit => express = "express";

let app = express();

module Routing = {
  let createOrderHandler: handler =
    (req, res) => {
      let order = {
        id: 0,
        reference: "",
        clientName: req->getQuery##userName,
        date: "",
        products: [||],
        totalPrice: 0.,
      };

      order->Controller.createOrder(() => {
        send(res, "Creating order for you...")
      });
    };
  let addProductHandler: handler =
    (req, res) => {
      req->ignore;
      send(res, "You want to add product to an order");
    };
  let removeProductHandler: handler =
    (req, res) => {
      req->ignore;
      send(res, "You want to remove a product from an order");
    };
  let updateProductQuantityHandler: handler =
    (req, res) => {
      req->ignore;
      send(res, "You want to update a product contained in an order");
    };
};

Database.connect();

post(app, "/create", Routing.createOrderHandler);
post(app, "/:id/addproduct", Routing.addProductHandler);
post(app, "/:id/removeproduct", Routing.removeProductHandler);
post(app, "/:id/updateproductquantity", Routing.updateProductQuantityHandler);

listen(app, 9000, () => {Js.log("Hello world, my server started!")});
