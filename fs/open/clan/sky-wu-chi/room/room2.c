// Room : /open/clan/sky-wu-chi/room/room2.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
這裡是小燕仔所開的錢莊，號稱高利率，借貸免
利息，你可以看到錢莊裡裡外外都打掃得乾乾淨淨，
這可發現老闆的愛好清潔，顯得每個人都來這裡存你
所辛辛苦苦賺來的錢，都存在這裡。只要打下幾個小
小的指令(cdonate),就能讓這個小小的幫派能夠有資
金做更大的發展喔。

LONG);
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/sky-wu-chi/room/room5.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "$HIC$燕仔牌錢莊$NOR$" );
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 2 */
  "存錢桶" : "",
  "bank" : "",
]) );
	setup();

	}
