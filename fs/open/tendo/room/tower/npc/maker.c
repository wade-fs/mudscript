#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
    set_name( HIW"陸步春"NOR ,({"maker lu","maker","lu"}));
    set("title", HIR"武器"HIC"鑄造大師"NOR);
    set("gender", "男性");
    set("age",43);
    set("attitude","friendly");
    set("long",@LONG

        他是鑄造武器的大師, 專門為武林俠士們鑄造順手的兵器,
        不過這些兵器不是隨便就能打造出來的, 材料方面可得費心
        一點去收集........
LONG);

    set("combat_exp",3000);
    set("str",36);
    set("con",34);
    set("int",32);
    set("max_kee",300);
    set("kee",300);
    set("max_force",500);
    set("force_factor", 2);
    set("force",500);
    set("no_kill",1);
    setup();
}

void init()
{
        add_action("do_select","select");
}

int accept_object(object who, object obj)
{

        if( obj->value() == 1000000 )
        {
        write("好!我去準備一下鑄造空手武器的工具!!\n");
        who->set_temp("money/unarmed",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2200000 )
        {
        write("好!我去準備一下鑄刀用的工具!!\n");
        who->set_temp("money/blade",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1800000 )
        {
        write("好!我去準備一下鑄弓用的工具!!\n");
        who->set_temp("money/bow",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2000000 )
        {
        write("好!我去準備一下鑄鞭用的工具!!\n");
        who->set_temp("money/whisk",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1600000 )
        {
        write("好!我去準備一下鑄匕首用的工具!!\n");
        who->set_temp("money/dagger",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1400000 )
        {
        write("好!我去準備一下鑄棍用的工具!!\n");
        who->set_temp("money/stick",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 1200000 )
        {
        write("好!我去準備一下鑄扇用的工具!!\n");
        who->set_temp("money/fan",1);
        destruct(obj);
        return 1;
        }
        if( obj->value() == 2400000 )
        {
        write("好!我去準備一下打劍用的工具!!\n");
        who->set_temp("money/sword",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "生鐵" )
        {
        command("say 這是塊生鐵!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",1);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "黃銅" )
        {
        command("say 這是塊黃銅!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",2);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "白銀" )
        {
        command("say 這是塊白銀!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",3);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "金子" )
        {
        command("say 這是塊黃金!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",4);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "翠玉" )
        {
        command("say 這是塊翠玉!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",5);
        destruct(obj);
        return 1;
        }
        if( obj->query("name") == "白玉" )
        {
        command("say 這是塊白玉!!您可是要打點兵器吧!!\n");
        who->set_temp("marks/metal",6);
        destruct(obj);
        return 1;
        }
        else
        {
        command("say 這位客官真是大方, 那我就恭敬不如從命囉!!\n");
        return 0;
        }
}

int do_select(string arg)
{
        object who=this_player();
        object bl,sw,st,un,fa,da,wh,bow;

	if( (int)this_player()->query("age") < 16 )
		return notify_fail("你年紀太小了﹐等老一點再來製造武器吧。\n");

        if( ( arg == "blade") && who->query_temp("money/blade") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了....\n\n");
            if ( who->query_temp("marks/metal",2) )
            bl=new("open/tendo/room/tower/obj/bl2");
       else if ( who->query_temp("marks/metal",4) )
            bl=new("open/tendo/room/tower/obj/bl4");
       else if ( who->query_temp("marks/metal",6) )
            bl=new("open/tendo/room/tower/obj/bl6");
       else if ( who->query_temp("marks/metal",5) )
            bl=new("open/tendo/room/tower/obj/bl5");
       else if ( who->query_temp("marks/metal",3) )
            bl=new("open/tendo/room/tower/obj/bl3");
       else bl=new("open/tendo/room/tower/obj/bl1");
           }
          who->delete("money/blade");
          who->delete("marks/metal");
          bl->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+bl->name()+"\n\n" NOR,users());
	return 1;
}

        if( ( arg == "sword") && who->query_temp("money/sword") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",2) )
            sw=new("open/tendo/room/tower/obj/sw2");
       else if ( who->query_temp("marks/metal",4) )
            sw=new("open/tendo/room/tower/obj/sw4");
       else if ( who->query_temp("marks/metal",6 ) )
        sw=new("open/tendo/room/tower/obj/sw6");
       else if ( who->query_temp("marks/metal",5) )
            sw=new("open/tendo/room/tower/obj/sw5");
       else if ( who->query_temp("marks/metal",3) )
            sw=new("open/tendo/room/tower/obj/sw3");
       else sw=new("open/tendo/room/tower/obj/sw1");
          }
          who->delete("marks/metal");
          who->delete("money/sword");
          sw->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+sw->name()+"\n\n" NOR,users());
	return 1;
}
       if( ( arg == "bow") && who->query_temp("money/bow") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",2) )
            bow=new("open/tendo/room/tower/obj/bow2");
       else if ( who->query_temp("marks/metal",4) )
            bow=new("open/tendo/room/tower/obj/bow4");
       else if ( who->query_temp("marks/metal",6 ) )
            bow=new("open/tendo/room/tower/obj/bow6");
       else if ( who->query_temp("marks/metal",5) )
            bow=new("open/tendo/room/tower/obj/bow5");
       else if ( who->query_temp("marks/metal",3) )
            bow=new("open/tendor/room/tower/obj/bow3");
       else bow=new("open/tendo/room/tower/obj/bow1");
          }
          who->delete("marks/metal");
          who->delete("money/bow");
          bow->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+bow->name()+"\n\n" NOR,users());
	return 1;
}
       if( ( arg == "whisk") && who->query_temp("money/whisk") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",2) )
            wh=new("open/tendo/room/tower/obj/wh2");
       else if ( who->query_temp("marks/metal",4) )
            wh=new("open/tendo/room/tower/obj/wh4");
       else if ( who->query_temp("marks/metal",6 ) )
            wh=new("open/tendo/room/tower/obj/wh6");
       else if ( who->query_temp("marks/metal",5) )
            wh=new("open/tendo/room/tower/obj/wh5");
       else if ( who->query_temp("marks/metal",3) )
            wh=new("open/tendo/room/tower/obj/wh3");
       else wh=new("open/tendo/room/tower/obj/wh1");
          }
          who->delete("marks/metal");
          who->delete("money/whisk");
          wh->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+wh->name()+"\n\n" NOR,users());
	return 1;
}
        if( ( arg == "dagger") && who->query_temp("money/dagger") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",2) )
            da=new("open/tendo/room/tower/obj/da2");
       else if ( who->query_temp("marks/metal",4) )
            da=new("open/tendo/room/tower/obj/da4");
       else if ( who->query_temp("marks/metal",6 ) )
            da=new("open/tendo/room/tower/obj/da6");
       else if ( who->query_temp("marks/metal",5) )
            da=new("open/tendo/room/tower/obj/da5");
       else if ( who->query_temp("marks/metal",3) )
            da=new("open/tendo/room/tower/obj/da3");
       else da=new("open/tendo/room/tower/obj/da1");
          }
          who->delete("marks/metal");
          who->delete("money/dagger");
          da->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+da->name()+"\n\n" NOR,users());
	return 1;
}

        if( ( arg == "stick") && who->query_temp("money/stick") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",4) )
            st=new("open/tendo/room/tower/obj/st4");
       else if ( who->query_temp("marks/metal",6) )
            st=new("open/tendo/room/tower/obj/st6");
       else if ( who->query_temp("marks/metal",2) )
            st=new("open/tendo/room/tower/obj/st2");
       else if ( who->query_temp("marks/metal",3) )
            st=new("open/tendo/room/tower/obj/st3");
       else if ( who->query_temp("marks/metal",5) )
            st=new("open/tendo/room/tower/obj/st5");
       else st=new("open/tendo/room/tower/obj/st1");
          }
          who->delete("money/stick");
          who->delete("marks/metal");
          st->move(who);
           message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+st->name()+"\n\n" NOR,users());
	return 1;
}

        if( ( arg == "unarmed") && who->query_temp("money/unarmed") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",4) )
            un=new("open/tendo/room/tower/obj/un4");
       else if ( who->query_temp("marks/metal",6) )
            un=new("open/tendo/room/tower/obj/un6");
       else if ( who->query_temp("marks/metal",3) )
            un=new("open/tendo/room/tower/obj/un3");
       else if ( who->query_temp("marks/metal",5) )
            un=new("open/tendo/room/tower/obj/un5");
       else if ( who->query_temp("marks/metal",2) )
            un=new("open/tendo/room/tower/obj/un2");
       else un=new("open/tendo/room/tower/obj/un1");
          }
          who->delete("marks/metal");
          who->delete("money/unarmed");
          un->move(who);
        message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+un->name()+"\n\n" NOR,users());
	return 1;
}
        if( ( arg == "fan") && who->query_temp("money/fan") )
        {
          if ( who->query_temp("marks/metal",1) )
          {
          write("鑄造大師將金屬丟入熔爐熔化後, 開始乒乒乓乓的鎚打起來了......\n\n");
            if ( who->query_temp("marks/metal",5) )
            fa=new("open/tendo/room/tower/obj/fa5");
       else if ( who->query_temp("marks/metal",4) )
            fa=new("open/tendo/room/tower/obj/fa4");
       else if ( who->query_temp("marks/metal",2) )
            fa=new("open/tendo/room/tower/obj/fa2");
       else if ( who->query_temp("marks/metal",3) )
            fa=new("open/tendo/room/tower/obj/fa3");
       else if ( who->query_temp("marks/metal",6) )
            fa=new("open/tendo/room/tower/obj/fa6");
       else fa=new("open/tendo/room/tower/obj/fa1");
          }
          who->delete("marks/metal");
          who->delete("money/fan");
          fa->move(who);
          message("system",
	HIW "\n\n一代鑄造大師陸步春為"+who->name()+"打造了一把絕世兵器"+fa->name()+"\n\n" NOR,users());
	return 1;
}

}






