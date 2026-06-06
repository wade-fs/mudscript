inherit ROOM;
void create() {
	set( "short", "血痕居-等活地獄" );
	set( "owner", "holeman" );
	set( "build", 10003 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room533.c",
		"east"      : "/open/clan/sky-wu-chi/room/room534",
		"south"     : "/open/clan/sky-wu-chi/room/room528.c",
	]) );
	set( "long", @LONG

    在極度炎熱的鐵地上，燃燒著火，眾生因為業力相感，聚集在
這裡，身體承受著以前因瞋恨業力所造作的惡報。他們本身已經很
痛苦了，再加上互相之間又形同仇敵，彼此瞋恨，用武器自相殘殺
。等他們全部死掉之後，虛空中會有聲音叫他們再活過來。當他們
全部死掉之後，虛空中會有聲音叫他們再活過來。當他們活過來以
後，因為惡業的關係，又再重新受苦，就這樣週而復始，無比痛苦
。

    他們的壽命是：人間的五十年是四大天王天的一天，四大天王
的五百年是等活地獄的一天，他們要在此受苦五百年。


LONG);
	setup();
	replace_program(ROOM);
}
