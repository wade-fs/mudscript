#include <command.h>
#include <ansi.h> 

inherit NPC;
int start_check( object me )
{
remove_call_out("start_check");
if( !me ) return 0;
command("say 你身上散發出陰靈之氣，難道你得到妖刀『村雨』？");
}
int start_blade(object who)
{
object wea;
remove_call_out("start_blade");
who=this_player();
if( !who ) return 0;
if(who->query_skill("fireforce",1)>=100&&who->query("get-evil-mblade")==0)
{
write("\n鑄匠將魔龍鱗丟入熔爐熔化後，加上你純正極火功\鍊金，一會兒就打好了妖刀！\n");
command("say 不過妖刀要血光才能發揮其功\用(blood)！");
command("say 傳說妖刀有某種神秘力量(power)！");
wea=new("/autoload/blademan/evil-mblade.c");
wea->move(who);
who->set("get-evil-mblade",1);
message("system",HIC"天空突然烏雲密佈，霎那間從天空中心擊落一道閃電。\n"NOR,users());
message("system",HIC"\n這道閃電霎有靈性般的擊向"+who->query("name")+"。\n"NOR,users());
message("system",HIY"\n同時間，大地震裂無數陰靈飛出聚集在"+who->query("name")+"身上。\n"NOR,users());
message("system",HIR"\n只見"+who->query("name")+"眼露紅光狂笑道 : \n\n\t\t妖刀終於現世\n\n\t\t我稱霸武林之日\n\n\t\t即將到來\n\n\t\t哈哈哈哈哈哈\n\n"NOR,users());
message("system",HIW"天雷地動～～"+who->query("name")+"縱聲長笑 : \n\n\t\t哈哈哈哈～～"HIG"妖刀"HIW"現世了。\n"NOR,users());
who->set("title","妖刀傳人");
return 1;
} else {
if(who->query_skill("fireforce",1)<100) command("say 你極火功\不夠純正(lv 100)！");
if(who->query("get-evil-mblade")==1) command("say 你已經有妖刀了！");
return 1;
}
}
int do_nod()
{
object me = this_player();
if(me->query("evil-mblade")!=1) return 0;
message_vision(HIY"$N看了看$n手上的妖刀。\n"NOR,this_object(),this_player());
command("sigh "+me->query("id"));
command("say 可惜刀身以毀，不過沒關西，我父親教了我一身好功\夫。");
command("say 只要你能拿到魔龍鱗和練得純正極火功\我就能幫你。");
        return 1;
}
void create()
{
    set_name("工匠",({"maker"}));
    set("title", "武器鑄造的");
    set("gender", "男性");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

        他是鑄造武器的工匠, 專門為武林俠客們鑄造順手的兵器, 
        不過這些兵器不是隨便就能打造出來的, 材料方面可得費心
        一點去收集........

LONG);
 
    set("combat_exp",2000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",50);
    set("kee",50);
    set("max_force",50);
    set("force_factor", 1);
    set("force",50);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set("chat_chance",3);
    set("chat_msg", ({
        "我的雙手啊～最是靈巧了～!!\n\n"
        "各種長短兵器～都能做的讓客官您滿意的～!!\n\n",
        "至於工錢嘛!! 可是不能馬虎的喲!!\n\n",
    }) );
    set("inquiry",([
    "工錢":"那就要看客官您要打造何種兵器了!!刀, 劍, 棍, 扇, 爪....都得要付錢喲!!\n",
    "刀":"鑄刀的價格嘛也不會很多啦!!就算您 10 兩金子好了!!不好意思, 騙加騙加啦\n",
    "劍":"打劍的時間花費最久了!!收個 20 兩金子可不算過份哪!!不好意思, 騙加騙加啦\n",
    "棍":"磨棍要花的功\夫較多!!酌量給您收個 12 兩金子!!不好意思, 騙加騙加啦\n",
    "扇":"扇子的製作較繁雜!!可得收個 15 兩金子呢!!不好意思, 騙加騙加啦\n",
    "爪":"空手武器的造型較簡單!!就算您 5 兩金子好了!!不好意思, 騙加騙加啦\n",
    ]));
    setup();
}

void init()
{
        object me = this_player();
        object ob;
if((ob=present("bad-evil-mblade",me))&&ob->name()=="受損的妖刀『村雨』")
        {
                call_out("start_check",1,me);
                add_action("do_nod","nod");
        }
        add_action("do_select","select");
if(me->query_temp("sumblade")==1&&me->query_temp("bad-blade")==1) {
    call_out("start_blade",1,me); }
}

int accept_object(object who, object obj)
{
object wea;
who=this_player();
        if( obj->value() == 50000 )
        {
        write("小的馬上拿這些工錢去準備一下鑄造空手武器的工具!!\n");
        who->set_temp("money/unarmed",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 100000 )
        {
        write("小的馬上拿這些工錢去準備一下鑄刀用的工具!!\n");
        who->set_temp("money/blade",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 120000 )
        {
        write("小的馬上拿這些工錢去準備一下鑄棍用的工具!!\n");
        who->set_temp("money/stick",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 150000 )
        {
        write("小的馬上拿這些工錢去準備一下鑄扇用的工具!!\n");
        who->set_temp("money/fan",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 200000 )
        {
        write("小的馬上拿這些工錢去準備一下打劍用的工具!!\n");
        who->set_temp("money/sword",1);
        destruct(obj);
        return 1;
        }
        if( obj->query_temp("name") == "黃甲金龍的眼珠" )
        {
        command("say 這位客官, 你真利害!!竟然能夠拿到黃甲金龍的眼珠!!\n");
        who->set_temp("marks/dragon",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "黃甲金龍的皮革" )
        {
        command("say 這位客官, 你真利害!!竟然能夠拿到黃甲金龍的皮革!!\n");
        who->set_temp("marks/dragon",2);
        return 1;
        destruct(obj);
        }
        if( obj->query("name") == "黃甲金龍的鱗片" )
        {
        command("say 這位客官, 你真利害!!竟然能夠拿到黃甲金龍的鱗片\n!!");
        who->set_temp("marks/dragon",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "黃甲金龍的銳齒" )
        {
        command("say 這位客官, 你真利害!!竟然能夠拿到黃甲金龍的牙齒!!\n");
        who->set_temp("marks/dragon",4);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "黃甲金龍的骨骼" )
        {
        command("say 這位客官, 你真利害!!竟然能夠拿到黃甲金龍的骨骼!!\n");
        who->set_temp("marks/dragon",5);
        destruct(obj);
        return 1;
        }
if(who->query("family/family_name")=="魔刀莫測"&&who->query("evil-mblade")==1)
{
if(obj->query("id")=="dragon scale"&&who->query_temp("sumblade")!=1)
        {
        command("say 哈哈！你拿到魔龍鱗了！妖刀現世咫日可待！\n");
        who->set_temp("sumblade",1);
        destruct(obj);
 } else
if(obj->query("id")=="bad-evil-mblade"&&who->query_temp("bad-blade")!=1)
        {
        command("say 呵呵！妖刀就要現世啦！\n");
        destruct(obj);
        who->set_temp("bad-blade",1);
        }
command("say 把我須要的東西給我，等一下再來！\n");
        return 1;
}
        if( obj->query("name") == "生鐵" )
        {
        command("say 這位客官, 這是塊生鐵哪!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "黃銅" )
        {
        command("say 這位客官, 這是塊黃銅哪!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",2);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "白銀" )
        {
        command("say 這位客官, 這是塊白銀哪!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "金子" )
        {
        command("say 這位客官, 這是塊黃金哪!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",4);
        destruct(obj);
        return 1;
        }
        else
        {
        command("say 這位客官真是大方, 那小的就恭賀不容從命囉\n!!");
        return 0;
        }
}

int do_select(string arg)
{
        object who=this_player();
        object bl,sw,st,un,fa;

        if( ( arg == "blade") && who->query_temp("money/blade") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄匠將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            bl=new("data/autoload/prayer/bl2");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            bl=new("data/autoload/prayer/bl4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            bl=new("data/autoload/prayer/bl6");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            bl=new("data/autoload/prayer/bl5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            bl=new("data/autoload/prayer/bl3");
       else bl=new("data/autoload/prayer/bl1");
          }
          who->delete("marks/dragon");
          who->delete("money/blade");
          who->delete("marks/metal");
          bl->move(who);
          write(this_object()->query_temp("name")+"將鑄好的刀拿給你看了看。\n\n"+
          "你覺得這一把刀異常地鋒利, 拿在手上頓覺自己刀法益發成長許\多。\n\n");
          return 1;
        }
    
        if( ( arg == "sword") && who->query_temp("money/sword") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄匠將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            sw=new("data/autoload/prayer/sw2");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            sw=new("data/autoload/prayer/sw4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            sw=new("data/autoload/prayer/sw6");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            sw=new("data/autoload/prayer/sw5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            sw=new("data/autoload/prayer/sw3");
       else sw=new("data/autoload/prayer/sw1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/sword");
          sw->move(who);
          write(this_object()->query_temp("name")+"將打好的劍拿給你看了看。\n\n"+
          "你覺得這一把劍所散發出來的劍氣可以使自己劍法益發成長許\多。\n\n");
          return 1;
        }

        if( ( arg == "stick") && who->query_temp("money/stick") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄匠將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            st=new("data/autoload/prayer/st4");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            st=new("data/autoload/prayer/st6");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            st=new("data/autoload/prayer/st2");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            st=new("data/autoload/prayer/st3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            st=new("data/autoload/prayer/st5");
       else st=new("data/autoload/prayer/st1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/stick");
          st->move(who);
          write(this_object()->query_temp("name")+"將打好的棍子拿給你看了看。\n\n"+
          "你覺得這一根棍子異常地順溜, 拿在手上頓覺自己棍法比武松強多了。\n\n");
          return 1;
        }

        if( ( arg == "unarmed") && who->query_temp("money/unarmed") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄匠將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            un=new("data/autoload/prayer/un4");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            un=new("data/autoload/prayer/un6");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            un=new("data/autoload/prayer/un3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            un=new("data/autoload/prayer/un5");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            un=new("data/autoload/prayer/un2");
       else un=new("data/autoload/prayer/un1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/unarmed");
          un->move(who);
          write(this_object()->query_temp("name")+"將打好的武器拿給你看了看。\n\n"+
          "你覺得這一把空手使用的武器很特別, 裝備在手上給你一股力量感。\n\n");
          return 1;
        }

        if( ( arg == "fan") && who->query_temp("money/fan") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄匠將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",3) ) 
            fa=new("data/autoload/prayer/fa5");
       else if( who->query_temp("marks/metal",2) && who->query_temp("marks/dragon",1) ) 
            fa=new("data/autoload/prayer/fa4");
       else if( who->query_temp("marks/metal",3) && who->query_temp("marks/dragon",5) ) 
            fa=new("data/autoload/prayer/fa2");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",2) ) 
            fa=new("data/autoload/prayer/fa3");
       else if( who->query_temp("marks/metal",4) && who->query_temp("marks/dragon",4) ) 
            fa=new("data/autoload/prayer/fa6");
       else fa=new("data/autoload/prayer/fa1");
          }
          who->delete("marks/dragon");
          who->delete("marks/metal");
          who->delete("money/fan");
          fa->move(who);
          write(this_object()->query_temp("name")+"將打好的武器拿給你看了看。\n\n"+
          "你覺得這一把扇子很稱手, 裝備在手上給你一股安全感與威風之態。\n\n");
          return 1;
        }

}

