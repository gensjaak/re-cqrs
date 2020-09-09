let conn =
  Mysql.createConnection(
    ~host="127.0.0.1",
    ~port=8889,
    ~user="cqrsuser",
    ~password="CHxnzVvAv87MkGrd",
    (),
  );

let connect = () => {
  Mysql.query(conn, "SHOW DATABASES", result => {
    switch (result) {
    | Ok(results) => Js.log(results.results)
    | Error(err) => Js.log(err##message)
    }
  });

  Mysql.endConnection(conn);
};
