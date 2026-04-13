# Music Player System (DSA-CS221)

A high-performance command-line Music Player System developed in **C++**. This project was created for the **CS221: Data Structures and Algorithms** course at **GIKI** to demonstrate the practical application of fundamental data structures in managing dynamic datasets.

---

## 🚀 Features

- **Dynamic Playlist Management**: Uses **Singly Linked Lists** for adding, removing, and navigating songs with efficient memory usage.
- **Persistent User History**: Implemented a **Binary Search Tree (BST)** to store playback history, allowing for $O(\log n)$ retrieval and automatic sorting by song duration.
- **Smart Recommendation Engine**: A custom algorithm that analyzes your most-played genres and suggests new tracks using **Queues**.
- **Playback Simulation**: A clean CLI interface that displays metadata including Artist, Duration, and Genre.

## 🛠️ Tech Stack

- **Language**: C++
- **Data Structures**: Linked Lists, Binary Search Trees (BST), Queues
- **Environment**: Windows (utilizes `Windows.h` for console management)

## 📂 Project Structure

- `LabProject.cpp`: The main source code containing the logic for the BST, Queue, and Linked List implementations.
- `song` struct: Stores song metadata (Title, Artist, Duration, Genre).

## ⚙️ How to Run

1. Clone the repository:
   ```bash
   git clone [https://github.com/your-username/music-player-system.git](https://github.com/your-username/music-player-system.git)
