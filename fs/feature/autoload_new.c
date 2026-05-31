//add by bss,can save some special setting if defined
//09/24/03
#include <dbase.h>
inherit F_DBASE;
#define NEED_SAVE ({"ex_def_power","ex_add_def","ex_lucky"})

void save_autoload(object me)
{
    object *inv;
    mapping list;
    int i,j;
    mixed *klist;

    me->clear_up_autoloads();
    inv=all_inventory(me);

    for(i=0;i<sizeof(inv);i++){
      if(!inv[i]->query_autoload()) continue;
      list = (mapping)inv[i]->query_entire_dbase();
      if( !list || !mapp(list) ) continue;
      if (sizeof(list)){
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
      }
      if(!klist || !sizeof(klist)) continue;
      for(j=0; j<sizeof(klist); j++)  {
        if(member_array(klist[j],NEED_SAVE)==-1) continue;
        me->a_set(base_name(inv[i])+"/"+klist[j],list[klist[j]]);
      }
    }
    return ;
}
void restore_autoload(object me)
{
    object *inv;
    mapping list;
    int i,j;
    mixed *klist;
    mixed type;

    inv=all_inventory(me);

    for(i=0;i<sizeof(inv);i++){
      if(!me->a_query(base_name(inv[i]))) continue;
      klist=keys(me->a_query(base_name(inv[i])));
      if(!klist || !sizeof(klist)) continue;
      for(j=0;j<sizeof(klist);j++)
        inv[i]->set(klist[j],me->a_query(base_name(inv[i])+"/"+klist[j]));
    }
    return ;
}


