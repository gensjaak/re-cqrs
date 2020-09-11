open ExpressUtils;

let testApiStatus = (_req, res) => {
  send(res, "API is running successfully...");
};

let createOrderHandler = (req, res) => {
  req->ignore;
  send(res, "Creating order for you...");
};

let addProductHandler = (req, res) => {
  req->ignore;
  send(res, "You want to add product to an order");
};

let removeProductHandler = (req, res) => {
  req->ignore;
  send(res, "You want to remove a product from an order");
};

let updateProductQuantityHandler = (req, res) => {
  req->ignore;
  send(res, "You want to update a product contained in an order");
};

let getProductsHandler = (_req, res) => {
  let next = response => json(res, response);

  Controller.getProducts(next);
};
