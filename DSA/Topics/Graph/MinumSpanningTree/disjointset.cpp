/*(/
most imp topic of the graph series appraentltly
they are ued to detmeien wether two poruiton of data belong ot same set of data or not 

used in a dynamic grpah 

main two functions 
    findingParent()
    findingUnion()
    )


what we require
    rank array = ( basicaly is the degerd of each node) intally 0 
    parrtent array = ( intally everhyone is there own parrent);



finding Union of two nodes 

    union of (u,v)
    find the ulitmate parent of u,v   pu , pv 
    find the rank of pu, pv
    conn4ct smaller rank to  larger ranK (alwasy )


the rason it is able to ans the quesiont does u n v belong to the same set or not i becz
it maintains a tree like sturcter were each member of a group have the same main parrent 
hence it jus hvae to compare the avlue of 
parrentarary [v] parrentaray[u] 


as this method takesl log(N) of time appraentluy 
thus we use something called 

path compression

so basicaly whawt it says that in all of our operations we only require the ulitmate parrent hence why should we not 
connect all to their main parrent thus it easees teh time compelxity

but beware we wont change the rank here as uit wold make no snse ( as rank == height) which helps here determine whidch will 
get attached and which wont 



why connectg smlaler ot larger : 
as it will take longer time time to ittriate to do the opposite 

*/