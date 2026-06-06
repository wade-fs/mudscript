inherit COMBINED_ITEM;
void create()
{
set_name("大岩石", ({"stone"}) );
set("long","一塊巨大的岩石, 可以使力看看能不能將它推開(move)!!\n");
set("unit", "座");
set("base_unit", "座");
set("no_sell",1);
set("value",100000);
set("base_weight", 10000000);
set_amount(1);
setup();
}

void init()
{
add_action("move_stone", "move");
}
int move_stone(string arg)
{
object ob,me;
me=this_player();
if (this_player()->query_temp("move_stone")!=1 && this_player()->query_temp("can_back")==1)
{
tell_object(this_player(),"你使力的將這塊大岩石推開, 只見一個鐵盒子藏在岩石下面的洞窟中!!\n");
new("/open/killer/island/obj/box2.c")->move(environment(this_player()));
ob=present("stone",environment(this_player()));
me->set_temp("move_stone",1);
destruct(ob);
return 1;}
else
{ 
tell_object(this_player(),"你推不動這塊岩石!!\n");
return 1;
}
}
