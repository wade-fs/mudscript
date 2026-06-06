inherit ITEM;
void create ()
{
set_name("魯仝的護身符",({"luton's amulet","amulet"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","這是一個極為普通的護身符，魯仝交給你的唯一線索。\n");
	set("value",1);
	set("unit","個");
	setup();
}}
