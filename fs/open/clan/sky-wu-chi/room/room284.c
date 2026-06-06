inherit ROOM;
void create() {
	set( "short", "$HIM$東銀河系$NOR$" );
	set( "owner", "cong" );
	set( "item_desc", ([
		"left_11_sword_line" : @ITEM

                          ─$BYEL$王者之路$NOR$─

                     $HIR$【$NOR$心劍$HIR$】$NOR$─ $HIR$求道之心，無劍之心，方達劍之心$NOR$

   $HIM$【$NOR$搏命$HIM$】$NOR$─ $HIM$以用刀的心來用劍，至生死度外$NOR$

      $HIG$【$NOR$無怨無尤$HIG$】$NOR$─ 劍之至高境界在於劍氣能融入人體

              $HIC$【$NOR$隨心所欲$HIC$】$NOR$─ $HIC$無招之劍$NOR$

 $RED$【$NOR$瀝血肝膽$RED$】$NOR$─ $RED$用劍之境界乃$NOR$「$RED$求心$NOR$」

        $MAG$【$NOR$忘棄紅塵$MAG$】$NOR$─ $MAG$先心傷，方能忘棄紅塵$NOR$

                    $WHT$【$NOR$天堂之翼$WHT$】$NOR$─ $WHT$起劍不定，翼舞天堂$NOR$

    $BLU$【$NOR$秋末悲歌$BLU$】$NOR$─ 「$BLU$器$NOR$」

 $HIY$【$NOR$日月同天$HIY$】$NOR$─ $HIY$日為陽、月為陰；陰陽相濟、日月分離$NOR$

              $HIB$【$NOR$慾望之海$HIB$】$NOR$─ $HIB$引動九地黃泉之氣，慾海始成形$NOR$

      $CYN$【$NOR$廬山不動一劍痕$CYN$】$NOR$─ $CYN$立地九分，發在意先$NOR$

ITEM,
	]) );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/killer/headkill/obj/w_dag",
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"amount9"  : 1,
		"file7"    : "/open/doctor/pill/human_pill",
		"amount4"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/killer/headkill/obj/e_dag",
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 14,
		"file9"    : "/open/killer/headkill/obj/i_dag",
	]) );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room239.c",
	]) );
	set( "long", @LONG
 這裡是傳說中 神秘的幻境 東銀河系

 $HIM$放眼望ㄑ，到處都是一道道劍痕。好像有人在此大戰ㄌ一場似的
 但是很快的你就會發覺你錯ㄌ！因為那些一道道四處分散的劍痕
 旁邊都有一行小字的劍訣。沒錯、這裡是一處練功地。$NOR$

     $HIC$『$NOR$
          $HIY$左邊的十一道劍痕$NOR$(left_11_sword_line)
                                              $HIC$ 』$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
