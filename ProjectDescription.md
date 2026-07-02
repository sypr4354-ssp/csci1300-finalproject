# Final Project Proposal: Avengers Initiative Terminal

## Theme
A text-based superhero strategy and tactical simulation game based on recruiting Marvel comic heroes, managing S.H.I.E.L.D. resources, upgrading combat tiers, and navigating a custom grid map.

## Planned Classes
* **Superhero Class:** Models individual tactical assets with attributes for name, base combat power, and comic book tier (Recruit, Avenger, Cosmic), dynamically calculating modified total combat power.
* **Director Class:** Tracks the player's director stats, active squad members, and current positioning coordinates on the map grid.
* **MissionTerminal Class:** Handles the core game loops, text rendering of the tactical map, enemy encounters, and menu system interfaces.

## Planned Limited Resource
* **S.H.I.E.L.D. Energy / Power Units:** Deploying heroes to missions, traveling to new coordinate sectors, or initializing training protocols drains a finite daily energy resource. If it reaches zero before objective completion, the operational window closes.

## Plan for Handling Time
* **Turn-Based Operational Days:** Every deployment or deep-space sector transition increments an "Operational Day." The player must clear the primary threats before a fixed count of calendar days expires.

## Extra Credit Options
* (TBA - List any extra features you hope to add here, or write "None")

## Tradeoff System
* **S.H.I.E.L.D. Tech vs. Cosmic Artifacts:** Players must choose how to distribute resource spending. Utilizing standard S.H.I.E.L.D. technology is reliable and cost-effective but caps a hero's max growth. Chasing raw cosmic artifacts grants massive tier upgrades (like "Cosmic" status) but carries random event penalties or high energy risk.

## Mapping Style
* **2D Sector Coordinates:** The tactical game world will map out key regional nodes (e.g., Stark Tower, Helicarrier Docks, Wakandan Outpost) mapped across a two-dimensional grid array where players move between sectors.

## Win/Lose Condition
* **Win Condition:** Defeating the final boss encounter and achieving a collective roster power level threshold before the calendar runs out.
* **Lose Condition:** Depleting operational budget/energy entirely, or letting the threat level timeline hit 100% saturation.
