# CAN (Controller Area Network)

*Planned — not yet covered with hands-on examples.*

CAN is the protocol used heavily in automotive and industrial systems, where multiple controllers need to communicate reliably over long distances and in electrically noisy environments. It's more advanced than UART/I2C/SPI and typically needs a dedicated CAN transceiver module (e.g. MCP2515) alongside the microcontroller.

## Key Concepts (preview)

- **CAN-H / CAN-L** — the two-wire differential signaling pair
- **Arbitration** — how multiple devices on the same bus avoid collisions and decide message priority
- **Termination resistors** — required at both ends of a CAN bus (typically 120Ω)

This section will be filled in once a CAN-based project (e.g. vehicle data logging, industrial monitoring) is added — see [Projects/Advanced/](../../Projects/Advanced/) and [Roadmap.md](../../Roadmap.md).
