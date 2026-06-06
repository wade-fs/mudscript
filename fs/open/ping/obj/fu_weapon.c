// made by ccat
//原先specail是為了使npc慕容復持有武器時 不至於被玩家找到bug(被給予自製武器之類的bug)而拿錯武器 造成技能使用錯誤
//補上英文的拼法分為special specail兩種 by blazakira 2011/10/30

#include <weapon.h>
inherit STABBER;

void create()
{
  set_name( "百變奇扇",({"special fan","fan","specail"}) );
  set_weight(15000);
  if( clonep() ) 
    set_default_object(__FILE__);
  else {
    set("long","慕容世家的奇異武器，可以變換成刀劍鞭等來使用。\n"
      +"( change <type>, ex: change sword )\n"
      +"( type : unarmed sword blade whip dagger stabber archery )\n");
    set("unit", "件");
    set("value",2000);
    set("material","steal");
  }         
  init_stabber(45);
  setup();
}

void init()
{
  add_action("do_change","change");
}

int do_change(string str)
{
  switch(str)
  {
    case "unarmed":
      set("skill_type", "unarmed");
      set_name("銀爪",({"silver claws","claws","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了一雙銀爪。\n");
      break;
    case "sword":
      set("skill_type", "sword");
      set_name( "銀劍",({"silver sword","sword","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀劍。\n");
      break;
    case "archery":
      set("skill_type", "archery");
      set_name( "銀弓",({"silver bow","bow","specail"}));
      //直接套用inherit BOW的內容 by blazakira
      if( !query("arrow/id") ) {
        set("can_hold",1);
        // 初始化....把裝備的箭設成id = none ,amount = 0
        set("arrow/id","none");
        set("arrow/amount",0);
        set("arrow/name","空的");
      }
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀弓。\n");
      break;
    case "blade":
      set("skill_type", "blade");
      set_name( "銀刀",({"silver blade","blade","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀刀。\n");
      break;
    case "dagger":
      set("skill_type", "dagger");
      set_name( "銀色匕首",({"silver dagger","dagger","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀色匕首。\n");
      break;
    case "throwing":
      if(userp(this_player()))
        return notify_fail("你變不出這種變化。\n");
      set("skill_type", "throwing");
      set_name( "銀釘之星",({"silver star","star","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀釘之星。\n");
      break;
    case "whip":
      set("skill_type", "whip");
      set_name( "銀色短鞭",({"silver whip","whip","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀色短鞭。\n");
      break;
    case "stabber":
    case "fan":
      set("skill_type", "stabber");
      set_name( "百變奇扇",({"special fan","fan","specail"}) );
      //直接套用inherit BOW的內容 by blazakira
      if( query("arrow/id") ) {
        set("can_hold",0);
        delete("arrow/");
      }
      write("百變奇扇開始作奇異的變化。\n百變奇扇變回原來的扇子。\n");
      break;
    case "staff":
      set("skill_type", "staff");
      set_name( "銀色法杖",({"silver staff","staff","specail"}));
      write("百變奇扇開始作奇異的變化。\n百變奇扇化成了銀色法杖。\n");
      break;
    default:
      write("百變奇扇左變右變，就是無法變成你要的東西。\n");
  }
  return 1;
}
