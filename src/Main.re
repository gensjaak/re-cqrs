open ExpressUtils;

let app = express();

// Connect to database at application start
Database.connect();

// Product routes
get(app, "/products", Router.getProductsHandler);
post(app, "/products", Router.testApiStatus);

get(app, "/products/:id", Router.testApiStatus);
put(app, "/products/:id", Router.testApiStatus);
delete(app, "/products/:id", Router.testApiStatus);
patch(app, "/products/:id", Router.testApiStatus);

// Order routes
get(app, "/orders", Router.testApiStatus);
post(app, "/orders", Router.createOrderHandler);

get(app, "/orders/:id", Router.testApiStatus);
put(app, "/orders/:id", Router.testApiStatus);
delete(app, "/orders/:id", Router.testApiStatus);
patch(app, "/orders/:id", Router.testApiStatus);

post(app, "/orders/:id/addproduct", Router.addProductHandler);
post(app, "/orders/:id/removeproduct", Router.removeProductHandler);
post(
  app,
  "/orders/:id/updateproductquantity",
  Router.updateProductQuantityHandler,
);

// Start server
listen(app, 9000, () => {
  // Started successfully 🎉
  Js.log("Hello world, my server started!")
});
