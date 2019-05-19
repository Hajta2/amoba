#ifndef TEXT_HPP
#define TEXT_HPP

#include "widgets.hpp"

class Text: public Widget
{
    protected:
    std::string txt;

    public:
        Text(int x,int y, int sx, int sy,std::string _text);
        void draw() override;
        void handle(genv::event ev) override;
        std::string GetValue();
};

#endif // TEXT_HPP
