inherit ITEM;
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
}
int do_open(string arg)
{
object me,ob;
me=this_player();
if(!arg||(arg!="box"))
return notify_fail("你要打開什麼？\n");
if(me->query_temp("get_note")==1)
return notify_fail("你已經打開了這個鐵盒子。\n");
if(me->query_temp("move_out")!=1)
return notify_fail("你打不開這個鐵盒子。\n");
else{
ob=new(__DIR__"note");
me->delete_temp("move_out");
message_vision("$N打開了鐵盒子，從你面取出了一張字條。\n",me);
ob->move(me);
me->set_temp("get_note",1);
return 1;
}
}
