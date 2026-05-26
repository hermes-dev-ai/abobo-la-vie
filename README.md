# 🔥 ABOBO LA VIE

<p align="center">
  <img src="https://img.shields.io/badge/C++20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/raylib-000000?style=for-the-badge&logo=raylib&logoColor=white" />
  <img src="https://img.shields.io/badge/OpenGL-5586A4?style=for-the-badge&logo=opengl&logoColor=white" />
  <img src="https://img.shields.io/badge/license-MIT-green?style=for-the-badge" />
</p>

<pre align="center">
    ╔═══════════════════════════════════════════╗
    ║    █████  ██████   ██████  ██████   ██████  ║
    ║   ██   ██ ██   ██ ██   ██ ██   ██ ██    ██ ║
    ║   ███████ ██████  ██   ██ ██████  ██    ██ ║
    ║   ██   ██ ██   ██ ██   ██ ██   ██ ██    ██ ║
    ║   ██   ██ ██████   ██████  ██████   ██████  ║
    ║                                               ║
    ║        ██       ██  ██ ███████                ║
    ║        ██       ██  ██ ██                     ║
    ║        ██   █   ██  ██ █████                  ║
    ║        ██  ██   ██  ██ ██                     ║
    ║         ██████ ██   ██ ███████                ║
    ║                                               ║
    ║       🎮  ACTION  •  OPEN WORLD  •  3D  🎮    ║
    ╚═══════════════════════════════════════════╝
</pre>

<p align="center">
  <i>🧩 Un jeu d'action open-world dans les rues d'Abobo, Côte d'Ivoire</i><br/>
  <b>Style :</b> GTA-like ｜ <b>Moteur :</b> raylib ｜ <b>Langage :</b> C++20
</p>

---

## 🖼️ APERÇU DU JEU

> ⚠️ *Ajoute ici tes captures d'écran du jeu !*

<p align="center">
  <table>
    <tr>
      <td align="center"><b>🏙️ Vue de la ville</b></td>
      <td align="center"><b>🚗 Conduite</b></td>
      <td align="center"><b>⚔️ Combat</b></td>
    </tr>
    <tr>
      <td><img src="assets/screenshots/city_view.png" width="250" alt="City View"/></td>
      <td><img src="assets/screenshots/driving.png" width="250" alt="Driving"/></td>
      <td><img src="assets/screenshots/combat.png" width="250" alt="Combat"/></td>
    </tr>
    <tr>
      <td align="center"><b>🗺️ Mini-carte</b></td>
      <td align="center"><b>🌙 Nuit</b></td>
      <td align="center"><b>🏪 Missions</b></td>
    </tr>
    <tr>
      <td><img src="assets/screenshots/minimap.png" width="250" alt="Minimap"/></td>
      <td><img src="assets/screenshots/night.png" width="250" alt="Night"/></td>
      <td><img src="assets/screenshots/missions.png" width="250" alt="Missions"/></td>
    </tr>
  </table>
</p>

---

## 🎯 CONCEPT

**Abobo La Vie** vous plonge dans un quartier populaire d'Abidjan où vous incarnez un jeune de la rue. Entre missions, combats et exploration, la vie à Abobo est un combat de tous les instants.

> 💬 *"À Abobo, on naît, on lutte et on gagne — ou on meurt en essayant."*

---

## 🕹️ CONTRÔLES

| Touche | Action |
|--------|--------|
| <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> | Déplacement |
| <kbd>←</kbd> <kbd>→</kbd> | Rotation |
| <kbd>ESPACE</kbd> | Tirer |
| <kbd>F</kbd> | Entrer/Sortir d'un véhicule |
| <kbd>SHIFT</kbd> | Sprint |
| <kbd>R</kbd> | Réinitialiser la position |

---

## 🏗️ FONCTIONNALITÉS

<details open>
<summary><b>🌍 Monde ouvert</b></summary>

- Génération procédurale de ville avec **bâtiments, routes, arbres, lampadaires**
- Quartiers variés : Abobo, Yopougon, Cocody, Plateau
- Cycle jour/nuit avec éclairage dynamique

</details>

<details open>
<summary><b>🚗 Véhicules</b></summary>

- Conduite avec physique temps réel
- Accélération, freinage, direction
- Entrée et sortie du véhicule (touche <kbd>F</kbd>)

</details>

<details open>
<summary><b>⚔️ Combat</b></summary>

- Système de tir avec projectiles
- 3 types d'ennemis avec IA de poursuite
- Barres de vie et système de dégâts

</details>

<details open>
<summary><b>🎯 Missions</b></summary>

| # | Mission | Lieu | Récompense |
|---|---------|------|------------|
| 1 | Aller à la gare | 🚉 Abobo Gare | 150 FCFA |
| 2 | Trouver le marché | 🏪 Marché d'Abobo | 200 FCFA |
| 3 | Récupérer des médicaments | 💊 Pharmacie | 250 FCFA |
| 4 | Payer les impôts | 🏛️ Mairie | 300 FCFA |
| 5 | Visiter Gbinta | 🏘️ Gbinta | 350 FCFA |
| 6 | Aller au camp PKK | ⚔️ PKK | 400 FCFA |
| 7 | Traverser vers Yopougon | 🌉 Yopougon | 450 FCFA |
| 8 | Explorer la forêt du Banco | 🌳 Banco | 500 FCFA |
| 9 | Aller au Plateau | 🏢 Plateau | 550 FCFA |
| 10 | 🔥 MISSION FINALE - Cocody | 🏆 Cocody | 1000 FCFA |

</details>

<details open>
<summary><b>📊 HUD</b></summary>

- **Mini-carte** en haut à gauche
- **Barre de santé** avec code couleur (vert > orange > rouge)
- **Argent** en FCFA
- **Score** et **chronomètre**
- **Indicateur de véhicule** en haut à droite
- **Viseur** central pour le tir

</details>

---

## 🛠️ INSTALLATION

### Prérequis

| OS | Commande |
|----|----------|
| 🍎 **macOS** | ```brew install raylib cmake``` |
| 🐧 **Linux** | ```sudo apt install libraylib-dev cmake build-essential``` |
| 🪟 **Windows** | ```vcpkg install raylib``` |

### Compilation

```bash
# Cloner
git clone https://github.com/hermes-dev-ai/abobo-la-vie.git
cd abobo-la-vie

# Compiler
mkdir -p build && cd build
cmake ..
make -j4

# Lancer !
./abobo-la-vie
```

---

## 📂 STRUCTURE

```
abobo-la-vie/
├── 📁 assets/          # Textures, modèles, sons
├── 📁 src/
│   ├── 🎮 main.cpp     # Point d'entrée
│   ├── 🎮 Game.cpp/hpp # Boucle de jeu
│   ├── 🏙️ World.cpp/hpp # Génération ville
│   ├── 🧑 Player.cpp/hpp # Joueur
│   ├── 🚗 Vehicle.cpp/hpp # Véhicule
│   ├── 👾 Enemy.cpp/hpp # Ennemis
│   ├── 🔫 Weapon.cpp/hpp # Armes
│   ├── 📋 Mission.cpp/hpp # Missions
│   └── 🖥️ HUD.cpp/hpp  # Interface
├── 📄 CMakeLists.txt
└── 📄 README.md
```

---

## 🧰 TECHNOLOGIES

| Technologie | Rôle |
|-------------|------|
| **C++20** | Langage de programmation |
| **raylib 5.5+** | Moteur graphique 3D (OpenGL) |
| **CMake 3.16+** | Système de build |
| **GLFW** | Gestion des fenêtres et entrées |
| **OpenGL 3.3+** | Rendu 3D |

---

## 🚀 ROADMAP

- [x] Monde ouvert procédural
- [x] Joueur 3D avec contrôles
- [x] Système de véhicules
- [x] IA ennemie
- [x] Système de combat
- [x] 10 missions
- [x] HUD complet
- [ ] 🎨 Textures et modèles réalistes (style GTA IV)
- [ ] 🔊 Sons et musique (ambiance Abidjan)
- [ ] 👥 PNJ et dialogues
- [ ] 💰 Économie (achat armes, véhicules)
- [ ] 🌙 Cycle jour/nuit complet
- [ ] 📱 Portage mobile

---

## 📸 CAPTURES D'ÉCRAN

> Les captures d'écran sont stockées dans `assets/screenshots/`.  
> Pour ajouter les tiennes, joue au jeu et prends des screenshots avec <kbd>F2</kbd>, puis mets-les dans ce dossier !

---

## 🤝 CONTRIBUTION

Les contributions sont les bienvenues !

1. Fork le projet
2. Crée ta branche : `git checkout -b feature/ma-feature`
3. Commit : `git commit -m 'Ajout de ma feature'`
4. Push : `git push origin feature/ma-feature`
5. Ouvre une Pull Request

---

## 📜 LICENCE

MIT License — Voir le fichier [LICENSE](LICENSE)

---

<p align="center">
  <b>🔥 ABOBO LA VIE — La rue, la vie, la lutte ! 🔥</b><br/>
  <i>Fait avec ❤️ pour Abobo et toute la Côte d'Ivoire 🇨🇮</i>
</p>
