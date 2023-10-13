function ListGroup() {
  const item = ["New York", "Sri Lanka", "Tokyo"];

  return (
    <div>
      <h1>List view</h1>
      <ul className="list-group">
        {item.map((item) => (
          <li key={item}>{item}</li>
        ))}
      </ul>
    </div>
  );
}
export default ListGroup;
