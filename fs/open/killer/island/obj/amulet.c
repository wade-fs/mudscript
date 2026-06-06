inherit ITEM;
void create ()
{
set_name("護身符",({"amulet"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","這是一個極為普通的護身符，與魯仝交給我們的護身符相似，你可以調查(examine)看看。\n");
        set("value",1);
        set("unit","個");
        setup();
}}
void init()
{
add_action("do_ex","examine");
}
int do_ex(string arg)
{
object me;
me=this_player();
if(!arg||(arg!="amulet"))
return notify_fail("你要調查什麼？\n");
if(me->query_temp("get_amulet")!=1)
return notify_fail("這護身符雖然外觀已經損毀，但是在背面卻有『魯仝』兩個字，看來剛剛
那具屍體就是石田麗子。\n");
else {
tell_object(me,"這護身符雖然外觀已經損毀，但是在背面卻有『魯仝』兩個字。\n");
message_vision("$N臉上露出十分訝異的表情。\n",me);
message_vision("$N倒退了幾步，不小心掉入了底板之下。\n",me);
me->move("/open/killer/island/b_q01");
me->set_temp("get_amulet",2);
me->set_temp("move_out",1);
return 1;
}
}
