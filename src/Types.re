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
type commandType =
  | CreateOrder(order)
  | AddProduct(product)
  | RemoveProduct(string)
  | UpdateProductQuantity(string, int);

[@genType]
type command = {
  type_: commandType,
  payload: order,
};
