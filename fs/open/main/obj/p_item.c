// made by ccat
//增加seteuid(getuid())的判別 補上doctor專用的限制
//與使用check_item之後可增加醫術(cure)的經驗值 同時增加內力消耗為代價 by blazakira 2011/11/2

#include "/open/open.h"
inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("薏仁草", ({"green item","item"}) );
  set("long",
    "此物乃製造薏仁丹之材料，經藥師調配(check_item green item)，方得食用(eat pill)。\n");
  set("unit", "棵");
  set("base_unit", "棵");
  set("value",1000);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("check_item","check_item");
  }
}

int check_item(string arg)
{
  int cure;
  if( (arg=="item" || arg=="green item") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure",1); //估計值為60
    if( cure > 9)
    {
      message_vision("$N試著將薏仁草製成藥丹。\n", user);
      cure /= 10; //估計值為6
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      ob=new(COMMON_OBJ"pill");
      ob->move(user);
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure*2)); //估計值為0~12
      else
        user->improve_skill("cure",random((int)cure/2)+1); //估計值為1~4
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將薏仁草製成藥丹。\n", user);
    return 1;
  }
  return 0;
}
