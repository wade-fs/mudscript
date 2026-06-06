inherit ITEM;
#include <ansi.h>

int i=3;
void create()
{
        set_name("一棵百年老樹",({"tree"}));
                
                set("unit", "棵");
                set("long",
                "一棵將近百年的樹木，樹上結實累累。長了一些奇特的果實。\n");
                set("no_get","1");
}

void init()
{
  add_action("do_shake","shake");
}


int do_shake(string arg)
{
 object obj;
 
 if(arg!="tree")
    return 1;
 i--; 
 if( i>1) {
   obj=new("/open/tendo/obj/fruit");
   obj->move("/open/tendo/kunlun/g2");
   message_vision("
一堆果實掉了下來....劈哩啪啦k的你頭暈眼花。
......" + HIC + "★........" + HIW + "＊....  " + HIB + "☆..
.... " + MAG + "※ .....     " + HIY + "★" + NOR + "..........
哇!!....天上繁星點點......
......@&#%#
\n",this_object());
} else {

message_vision("你搖了老半天，只掉下了幾片樹葉。\n",this_object());
} 

 return 1;
}
