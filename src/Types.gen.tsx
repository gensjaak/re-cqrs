/* TypeScript file generated from Types.re by genType. */
/* eslint-disable import/first */


// tslint:disable-next-line:interface-over-type-literal
export type product = {
  readonly id: number; 
  readonly name: string; 
  readonly unitPrice: number; 
  readonly quantity: number; 
  readonly totalPrice: number
};

// tslint:disable-next-line:interface-over-type-literal
export type order = {
  readonly id: number; 
  readonly reference: string; 
  readonly clientName: string; 
  readonly date: string; 
  readonly products: product[]; 
  readonly totalPrice: number
};

// tslint:disable-next-line:interface-over-type-literal
export type commandType = 
    { tag: "CreateOrder"; value: order }
  | { tag: "AddProduct"; value: product }
  | { tag: "RemoveProduct"; value: string }
  | { tag: "UpdateProductQuantity"; value: [string, number] };

// tslint:disable-next-line:interface-over-type-literal
export type command = { readonly type_: commandType; readonly payload: order };
