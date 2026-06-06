#include <weapon.h>
  inherit ITEM;
void create()
{
set_name("葉  狂",({"ya"}));
set("unit","位");
set("long","這是四大惡人的師父『嗜血狂魔』葉狂，
   三十年前無惡不做的他，在武林中腥風血雨，最後
   被瀧山派第五代掌門任溥文打敗並鎖在寒冰地牢中
   不見天日\n");
  set("no_get",1);                    
        setup();
}
