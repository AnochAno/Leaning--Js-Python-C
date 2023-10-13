function Message(){
    const name = 'Kanna';
    if (name)
        return <h1>Hello {name}</h1>;
    
    return <h2>Hello world</h2>

}
export default Message;