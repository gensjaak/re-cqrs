[@genType]
type product = {
  id: int,
  name: string,
  unitPrice: float,
  quantity: int,
  totalPrice: float,
};

[@genType]
type order = {
  id: int,
  reference: string,
  clientName: string,
  date: string,
  products: array(product),
  totalPrice: float,
};

[@genType]
type command =
  | CreateOrder(order)
  | AddProduct(product)
  | RemoveProduct(string)
  | UpdateProductQuantity(string, int)
  | GetProducts;

[@genType]
type callback = Js.Json.t => unit;
