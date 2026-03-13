# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]

### Added
- Core P2P networking primitives for distributed computation.
- Node discovery and peer-to-peer messaging.
- Basic fault tolerance and heartbeat/ping mechanisms.
- Integration with Vix AI Tensor and Vix AI NN for distributed training and computation.
- Unit tests for network connectivity, message passing, and failure recovery.

### Changed
- N/A

### Fixed
- N/A

---

## [0.1.0] - 2026-03-13

### Added
- Initial release of Vix AI Distributed library.
- Core classes:
  - `Node` for representing a network participant.
  - `NetworkManager` for managing peer connections and messaging.
  - `DistributedEngine` for running distributed computations.
- Basic support for serialization and secure message transfer.
- CMake build system with options for tests, warnings, and installation.
- Example programs demonstrating simple P2P communication and distributed tasks.
- Fully compatible with Vix AI Tensor and NN for distributed computation.

### Changed
- N/A

### Fixed
- N/A
