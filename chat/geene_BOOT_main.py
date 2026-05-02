from fastapi import FastAPI
from pydantic import BaseModel
from langchain_ollama import ChatOllama

app = FastAPI()

llm = ChatOllama(model="phi3")

class Message(BaseModel):
    text: str

@app.post("/chat")

def chat(msg: Message):
    response = llm.invoke(msg.text)
    return {"response": response.content}
from fastapi.responses import HTMLResponse

@app.get("/", response_class=HTMLResponse)
def home():
    with open("htjs.html") as f:
        return f.read()