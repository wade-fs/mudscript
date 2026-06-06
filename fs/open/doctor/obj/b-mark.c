//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/3/28

#include <ansi.h>
inherit F_AUTOLOAD;
inherit ITEM;

void create()
{
    set_name(HIY + "入閣令" + NOR, ({"book_mark"}));
    set("long","一張入藏經閣的令牌！使用完畢應該要還給華佗。\n");
    set_weight(50);
    set("no_get",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_put",1);
    set("no_sell",1);
    set("no_sac",1);
    set("no_drop",1);
    set("unit","面");
    setup();
}

void init()
{
  add_action("do_search","sea");
  add_action("do_search","sear");
  add_action("do_search","searc");
  add_action("do_search","search");
  add_action("do_give","gi");
  add_action("do_give","giv");
  add_action("do_give","give");
  add_action("do_take","take");
}

int do_give(string arg)
{
  string target,item;
  object who,ob=this_object(),me=environment(ob);
  if(!arg)
    return 0;
  if( sscanf(arg,"%s to %s",item,target)==2 || //保留這個判斷是為了指定target參數的存在
      sscanf(arg,"%s %s",target,item)==2 ); //需保留此分號 否則會與下方衝突
  else return notify_fail("你要給誰什麼東西﹖\n");
  if(!objectp(who = present(target,environment(me))) || !living(who)) //使用這個判斷是為了確定與目標同一間房間
    return notify_fail("這裡沒有這個人。\n");
  if(item==query("id") && who->query("id")=="master tor")
  {
    set("no_give",0); //關閉本物件的no_give 以便於在下方的return 0中 接著使用原指令give的判斷跟動作==交給對方
  }
  return 0;
}

int do_search(string arg)
{
  object ob=this_object(),me=environment(ob);
  int k=me->query_temp("check_book_times");
  if(!k) me->set_temp("check_book_times",100);
  if(!me->query("quest/doctor_book/allow")) return 0; //沒交給華佗靈魂珠就不能用此指令
  if(!arg && environment(me)->query_temp("check_book_ok")==me->query("id")) {
    tell_object(me,"你覺得左前方的書架(bookshelf)怪怪的。\n");
    return 1;
  }
  else if(!arg && random(k)==1) {
    environment(me)->set_temp("check_book_ok",me->query("id"));
    tell_object(me,"你覺得左前方的書架(bookshelf)怪怪的。\n"); //出現這訊息 順便在該房間設記號
    return 1;
  }
  else if(arg=="bookshelf" && environment(me)->query_temp("check_book_ok")==me->query("id")) {
    tell_object(me,"你覺得這書架右下方第二排左側數來第三本書有些異樣。\n(take book from bookshelf)\n");
    return 1;
  }
  else return 0;
}

int do_take(string arg)
{
  object ob=this_object(),me=environment(ob);
  if(!me->query("quest/doctor_book/allow")) return 0;
  if(!arg && environment(me)->query_temp("check_book_ok")==me->query("id") && environment(me)->query_temp("needleup") > 0) {
    tell_object(me,"你要拿什麼東西﹖\n");
    return 1;
  }
  else if(arg=="book from bookshelf" && environment(me)->query_temp("check_book_ok")==me->query("id")) {
    message_vision(HIW + "正當你想碰觸書本的時候，忽然從書中發出一道白光，白光中出現隱隱人影宛若似曾相似。\n" + NOR,me);
    if(!me->query("quests/doctor_book")) {
      tell_object(me,HIW
"慈眉銀髮的老先生對你說：辛苦你了，為了找齊我的靈魂，一定費了不少功\夫吧，看到本門\n"+
"　　　　　　　　　　　　弟子還有你在真讓我感到欣慰。我殘存的靈魂寄託在這本書上見\n"+
"　　　　　　　　　　　　證了本門的興衰，也見到了你帶來的希望，既然你能夠拯救我，\n"+
"　　　　　　　　　　　　那我就相信你能再興銀針門的榮光。這本書對你必定有所助益。\n" + NOR);
      message_vision(HIY + "你的神農氏醫源功\力更上一層。\n" + NOR,me);
      me->set("functions/shen-nongshi_cure/level",1);
      me->set("quests/doctor_book",1);
    }
    else {
      tell_object(me,"慈眉銀髮的老先生對你說：是你呀，書本遺失了嗎？這次不要再不見囉。\n");
    }
    if(me->query("id")=="doctor") {
      new("/open/doctor/doctor_book/obj/book2")->move(me);
      message_vision("老先生給$N一本有點不同的醫書" + HIW + "《" + YEL + "銅人腧穴針灸圖經" + HIW + "》" + NOR + "。\n",me);
    }
    else {
      new("/open/doctor/doctor_book/obj/book")->move(me);
      message_vision("老先生給$N一本平凡無奇的醫書《神農氏醫譜》。\n",me);
    }
    message_vision("使用的指令為﹕perform yu-needle.needleup\n",me);
    return 1;
  }
  return 0;
}

int query_autoload()
{
    return 1;
}
