inherit ROOM;

void create()
{
	set("short","野人洞窟");
	set("long",@LONG
洞窟內空間並不大，勉強擺放著一些雜物與桌子，桌上擺放著未
食完的野食，看起來不知是哪一種生物的殘骸被丟棄在桌子四周，由
屍骸上殘留有齒痕的狀態猜測，住在這裡的”生物”有著強健的牙齒
。
LONG);
	set("exits",([
"west":__DIR__"e08",
]));
	setup();
}
