<div id="Make_Group" class="page" style="display:none;">
    <section id="Settings">
        <form action="" method="post">
            <div class="number group_space">
                <div class="group_space">
                    <input type="radio" id="nbA" name="nbgrp_check" checked onclick="Group_NumberA();" />
                    <label for="nbA" onclick="Group_NumberA();"><h4 id="nbgrp_text">Nombre de groupes :</h4></label></br>
                    <input id="nbgrp" type="number" name="nbgrp" min="2" max="50" value="2" step="1" onchange="Show_Group_Names();"/>
                </div>
                <div class="sep group_space"></div>
                <div class="group_space">
                    <input type="radio" id="nbB" name="nbgrp_check" onclick="Group_NumberB();"/>
                    <label for="nbB" onclick="Group_NumberB();"><h4 id="nbppl_text" style="color:gray;">Nombre de participants :</h4></label></br>
                    <input id="nbppl" type="number" name="nbgrp" min="2" max="100" value="2" step="1" disabled="true" onchange="Show_Group_Names(); Detect_Min();" />
                    </br>
                    <label for="nbB2"><h4 id="average_text" style="color:gray;">Ecart permis :</h4></label></br>
                    <input id="average" type="number" name="average" min="0" max="50" value="1" step="1" disabled="true" />
                </div>
            </div>
            <hr>
            
            <div class="group_space">
                <label for="group_name"><h4>Nom des groupes : </h4></label>
                <select id="group_name" onchange="Show_Group_Names();">
                    <option value="num" selected>Numérique</option>
                    <option value="col">Couleurs</option>
                </select>

                <input id="group_name_unique" type="text" name="group_name" title="Lettres et Chiffres" placeholder="Entrer un nom à ajouter" pattern="[A-Za-z0-9]*" />
                <button onclick="Add_Custom(event, 'group_name_unique', 'names_list', 'names');">+</button>

                <div id="names_list"></div>

                <div id="error_names">
                    <strong>Attention !</strong> Pas suffisamment de Noms pour le Nombre de Groupe demandé</br>
                    Les noms manquant seront remplacés par des chiffres
                </div>
            </div>
            <hr>

            <div class="group_space">
                <div>
                    <label for="role_name"><h4>Rôles : </h4></label>
                    <input id="role_name" type="text" name="role_name" title="Lettres et Chiffres" placeholder="Entrer un rôle à ajouter" pattern="[A-Za-z0-9]*" />
                    <button onclick="Add_Custom(event, 'role_name', 'roles_list', 'roles');">+</button>
                </div>

                <div id="roles_list"></div>
            </div>
            <hr>

            <div class="group_space">
                <h4>Critères de génération des groupes : </h4>
                <div id="criteres"><p>Aucun critères</p></div>
            </div>
            <hr>

            <div id="generate" class="div-btn" onclick="Generate();">Générer</div>
        </form>
    </section>

    <section id="Groups">
        <div class="btn div-btn" onclick="Page_Lists();">Choisir une autre liste</div>

        <div id="student_list"><p>Erreur pour charger la liste</p></div>

        <div id="export" onclick="Export_File();"></div>
    </section>
</div>