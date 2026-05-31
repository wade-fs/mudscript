// updated.c
#include <ansi.h>
void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int v1, v2;
	string m;
	mapping my;

	my = ob->query_entire_dbase();
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];

  if(ob->query("class") != "taoist" && ob->query("spells/feeblebolt/level") > 100) {
    ob->delete("spells/feeblebolt/level",100);

    ob->set("spells/feeblebolt/level",100);
    tell_object(ob,HIR"你的蒼冥之箭等級不正常，將回復至等級 100 。\n"NOR);
  }
 if(ob->query("class") != "taoist" && ob->query("spells/missible/level") > 100)
 {
    tell_object(ob,HIR"你的紫幽之箭等級不正常，將回復至等級 100 。\n"NOR);
    ob->delete("spells/missible/level",100);
    ob->set("spells/missible/level",100);

 }

}
