let conn =
  Mysql.createConnection(
    ~host="127.0.0.1",
    ~port=8889,
    ~user="cqrsuser",
    ~password="CHxnzVvAv87MkGrd",
    ~database="order_hut",
    (),
  );

let connect = () =>
  Mysql.query(conn, "SELECT NOW();", queryResult => {
    switch (queryResult) {
    | Ok(response) =>
      Js.log2("Connected to database successfully at:", response.results)
    | Error(err) =>
      Js.log2("Error while connecting to remote database", err##message)
    }
  });

let disconnect = () => Mysql.endConnection(conn);
