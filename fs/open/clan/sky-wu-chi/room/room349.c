inherit ROOM;
void create() {
	set( "short", "小雪球之家" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room346",
	]) );
	set( "long", @LONG
經過蜿埏的長廊後, 你來到了內房, 往東私乎是某人的臥房, 往東通
往書房, 往南是水雲軒。輕羅紗窗外飄著朵朵的白雲, 淡淡的翠竹葉
延伸至室內, 清蔥的翠綠籠罩著此處, 佳木籠蔥, 奇花爛爛, 一帶清
流從花木深處瀉於石縫之中, 清風微拂, 翠竹搖曳, 藤蘿掩映中, 你
的眼皮漸漸感到沉重了。

LONG);
	setup();
	replace_program(ROOM);
}
