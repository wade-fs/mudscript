inherit ROOM;
void create() {
	set( "short", "$HIC$西銀河系$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"file1"    : "/open/capital/obj/4-4",
		"amount2"  : 1,
		"amount10" : 1,
		"file5"    : "/open/gsword/obj1/bloodsword",
		"file10"   : "/open/capital/guard/gring",
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
	]) );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room239",
	]) );
	set( "long", @LONG
這裡是傳說中 神秘的幻境 西銀河系

      $HIC$拂天光 照汗青 一步人生終是迷$NOR$
      $HIC$石中火 夢中生 羽扇輕搖任風流$NOR$

四周環繞著悠揚的吟詩聲 瀰漫著一股濃濃的詭異氣氛

$HIM$風颯颯的吹著──!! 雲緩緩的飄著──!!$NOR$
$HIM$雨零星的下著──!! 閃閃的星光像雷電般的落下──!!$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
