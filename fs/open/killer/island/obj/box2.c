inherit ITEM;
#include <ansi.h>
void create ()
{
set_name("金屬箱",({"box"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","一個用金屬鑄造十分密合的箱子，工藝十分精緻。");
        set("no_get",1);
        set_max_encumbrance(10000000);
        set("value",1);
        set("unit","盒");
        setup();
}}
int is_container() { return 1; }
void init()
{
add_action("do_open","open");
}
int do_open(string arg)
{
object me,ob;
me=this_player();
if(!arg||(arg!="box"))
return notify_fail("你要打開什麼？\n");
if(me->query_temp("openbox")==1)
return notify_fail("你已經打開過這個金屬箱了。\n");
if(!me->query_temp("move_stone"))
return notify_fail("你不知道該如何打開這個箱子。\n");
else{
ob=new("/open/killer/island/obj/card");
tell_object(me,HIY"
你打開了盒子，只見其中金光閃閃，裝滿了各式各樣的寶物!!
你在之中發現了一塊「令牌」，外貌非常熟悉，原來是一塊黑牙聯的殺手密令!!
盒子中裝著各式各樣的寶物，令你不禁想拿走一些!!
\n"NOR);
ob->move(me);
me->set_temp("openbox",1);
return 1;
}
}
