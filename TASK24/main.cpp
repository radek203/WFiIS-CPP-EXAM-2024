#include <iostream>
#include <vector>

using std::cout;

class Object {
public:
	virtual std::string print() {
		return "";
	}
};

class ConsoleObject : public Object {

};

class ConsoleLine : public ConsoleObject {
	std::string print() override {
		return "Console Line";
	}
};

class ConsoleText : public ConsoleObject {
	std::string print() override {
		return "Console Text";
	}
};

class GuiObject : public Object {

};

class GuiLine : public GuiObject {
	std::string print() override {
		return "Gui Line";
	}
};

class GuiText : public GuiObject {
	std::string print() override {
		return "Gui Text";
	}
};

int main()
{
    std::vector<Object*> objs;
    ConsoleObject*console0=new ConsoleLine();
    ConsoleObject*console1=new ConsoleText();
    GuiObject* gui0=new GuiLine();
    GuiObject* gui1=new GuiText();
    objs.push_back(console0); objs.push_back(console1);
    objs.push_back(gui0); objs.push_back(gui1);
    for(unsigned i=0; i !=objs.size();i++)
    cout<<objs[i]->print()<<",";
}

// Console Line,Console Text,Gui Line,Gui Text,