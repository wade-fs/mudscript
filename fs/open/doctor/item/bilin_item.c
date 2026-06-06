// 為保障doctor權利..只允許給doctor..check
//排版 調整check_item訊息 與增加check_item之後能增加醫術(cure)的經驗值 by blazakira 2011/11/1

inherit COMBINED_ITEM;

void create()
{
  seteuid(getuid());
  set_name("十年梗樹莖",({"tree item","item"}));
  set("long",
    "此乃銀針門掌門華陀先生所精心栽培的梗樹，此樹以各種不同藥物之合成肥料所種，有顧本\n"+
    "蓓元之效，可外敷亦可內用(你可以check_item tree item 及make tree item來提煉此藥。\n此物須經過醫者精湛的醫術方可提煉。\n");
  set("unit", "棵");
  set("base_unit", "棵");
  set("no_sell",1);
  set("value",2500);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("check_item","check_item");
    add_action("make_item","make");
  }
}

int check_item(string arg)
{
  int cure;
  string str;
  if( (arg=="item" || arg=="tree item") && (query("unit") == "棵") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成藥丸!!\n");
    cure = user->query_skill("cure"); //估計值為160
    cure = cure /3; //估計值為53
    if( cure > 10)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/doctor/pill/life_pill");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將十年梗樹莖製成保命丹。\n", user);
      if( user->query("force") < (int)cure*2 )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure*2);
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure/4)); //估計值為0~13
      else
        user->improve_skill("cure",random((int)cure/8)+1); //估計值為1~7
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將樹莖製成保命丹。\n", user);
    return 1;
  }
  return 0;
}

int make_item(string arg)
{
  int cure;
  string str;
  if( (arg=="item" || arg=="tree item") && (query("unit") == "棵") )
  {
    object user,ob;
    user = this_player();
    if(user->query("class")!="doctor")
      return notify_fail("你職業不是醫者無法將藥株製成膏藥!!\n");
    cure = user->query_skill("cure"); //估計值為160
    cure = cure /3; //估計值為53
    if( cure > 10)
    {
      str=user->query_skill_mapped("force");
      if( !str )
        return notify_fail("你並沒有催動內力的方法(enable)，導致無法繼續煉製下去!!\n");
      ob=new("/open/common/obj/plaster");
      message_vision("$N用"+to_chinese(str)+"催動內力於掌心處，試著將"+query("name")+"煉製成"+ob->query("name")+"。\n", user);
//      message_vision("$N試著將十年梗樹莖製成金創藥。\n", user);
      if( user->query("force") < (int)cure )
        return notify_fail("你的內力不足，導致無法繼續煉製下去!!\n");
      user->add("force",-(int)cure);
      ob->move(this_player());
      ob->add_amount((int)cure);
      if( user->query_skill("cure",1) < 120 )
        user->improve_skill("cure",random((int)cure/4)); //估計值為0~13
      else
        user->improve_skill("cure",random((int)cure/8)+1); //估計值為1~7
      add_amount(-1);
    } else
      message_vision("$N的醫術太低，無法將樹莖製成金創藥。\n", user);
    return 1;
  }
  return 0;
}
