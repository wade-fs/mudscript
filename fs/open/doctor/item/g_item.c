// made by ccat
// 為保障doctor權利..只允許給doctor..check
//排版 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("還精草", ({"gin item","item"}) );
  set("long",
    "此物乃製造還精丸之材料，須經藥師調配(check_item gin item)，方得以吞服\n(eat pill)。\n");
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
  string str;
  if( (arg=="item" || arg=="gin item") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure"); //估計值為160
    cure = cure /4; //估計值為40
    if( cure > 10)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/doctor/pill/g_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將還精草製成還精丸。\n", user);
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      ob->move(user);
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure/2)); //估計值為0~20
      else
        user->improve_skill("cure",random((int)cure/5)+1); //估計值為1~9
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將還精草製成還精丸。\n", user);
    return 1; 
  }
  return 0;
}
