inherit ITEM;
#include <ansi.h>
void create ()
{
set_name("鐵盒子",({"iron box","box"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","這是一個普通的鐵盒子，似乎可以打開(open)的樣子。");
        set("no_get",1);
        set("value",1);
        set("unit","盒");
        setup();
}}
void init()
{
add_action("do_open","open");
add_action("do_close","close");
}
int do_open(string arg)
{
object me,ob;
me=this_player();
if(!arg||(arg!="box"))
return notify_fail("你要打開什麼？\n");
if(me->query_temp("openbox")==1)
return notify_fail("你已經打開了這個鐵盒子。\n");
else{
ob=new(__DIR__"note");
me->delete_temp("move_out");
message_vision(HIY"
$N打開了盒子，只見其中金光閃閃，裝滿了各式各樣的寶物!!
$N在之中發現了一塊令牌，外貌非常熟悉，原來是一塊黑牙聯的殺手密令!!
盒子中裝著各式各樣的寶物，令你不禁想拿走一些!!
\n"NOR,me);
ob->move(me);
me->set_temp("openbox",1);
return 1;
}
}
