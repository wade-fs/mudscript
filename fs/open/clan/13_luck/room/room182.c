inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room168",
		"east"      : "/open/clan/13_luck/room/room182.c",
	]) );
	set( "long", @LONG

　　穿過倒塌的樹幹，走進了一大片的樹林中，謎樣般的森林，終年
濃霧不散，眼前只見白茫茫的一大片，伸手不見五指。風吹的樹木沙
沙作響，看起來有種陰森森的詭異氣氛，路旁的灌木叢中似乎有東西
在動，你心想該不會有什麼毒蛇猛獸吧！

LONG);
	setup();
	replace_program(ROOM);
}
