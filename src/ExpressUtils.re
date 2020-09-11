type express;
type response;
type request = Js.Types.obj_val;
type handler = (request, response) => unit;

[@bs.send] external post: (express, string, handler) => unit = "post";
[@bs.send] external get: (express, string, handler) => unit = "get";
[@bs.send] external put: (express, string, handler) => unit = "put";
[@bs.send] external patch: (express, string, handler) => unit = "patch";
[@bs.send] external delete: (express, string, handler) => unit = "delete";

[@bs.send] external send: (response, string) => unit = "send";
[@bs.send] external json: (response, 'a) => unit = "json";
[@bs.send] external listen: (express, int, unit => unit) => unit = "listen";

[@bs.module] external express: unit => express = "express";

let query = [%raw "(request) => request.query"];
