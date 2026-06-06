#include <weapon.h>
  inherit SWORD;
void create()
{
 set_name("劍",({ "snake sword","sword"}));
      set_weight(100);                                       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("unit","把");
      set("long", "
這把劍是由古代名鑄造師陳洛鑄成的，柄上雕著一隻栩栩如生的狼，狼的
眼睛正冷冷的看著你，劍身則略作龍形，仿彿要將你活生生的撕裂，據說
這把劍威力無窮，只有最精通劍法的人才敢使用它．\n") ;
		 set("value", 400);
		 set("material","crimsonsteel");
set("wield_msg","\n
$N把龍狼劍握在手中，突然劍柄上的狼發出一陣淒厲的狼嚎，一股黑氣衝出，
化做狼形圍繞在$N的身旁，劍上蟄伏以久的龍魂在$N強烈的鬥氣趨動下一飛
衝天，兩隻神獸競相呼號，發揮這把劍裡蘊涵的無比力量. \n");
									

	    set("unwield_msg","
$N把龍狼劍放下，龍神和狼神又化為兩股黑氣，潛回劍內
，靜待下一次的戰鬥\n");
  init_sword(5000);
	setup();
  }
}
