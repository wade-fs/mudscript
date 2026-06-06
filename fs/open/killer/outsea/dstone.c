inherit ITEM;
void create()
{
set_name("龍神水珠", ({"dragon_stone","stone"}));
set("long",@LONG
傳說中，水龍神進出水底時所用的神奇水珠，能增加持有者抵抗
進入水壓強大的地方。
LONG);
set("unit","顆");
set_weight(100);
set("value",0);
set("no_save",1);
set("no_sec",1);
setup();
}
